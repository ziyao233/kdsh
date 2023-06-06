#include"arch.h"
#include"syscall.h"
#include"malloc.h"
#include"tools.h"

#define PAGE_SIZE 4096
#define HALF_PAGE_SIZE (PAGE_SIZE / 2)

#define free_size	(PAGE_SIZE - pool->freeOffset - sizeof(Pool))
#define inpage_offset(p) 	((PAGE_SIZE - 1) & ((size_t)(p)))
#define page_start(p)	((void *)(((size_t)(p)) & ~(PAGE_SIZE - 1)))
/*
 *	This macro uses the fact that mmap() always returns an address
 *	aligned by the page boundary, and a large object needs only a
 *	sizeof(size_T) bytes header
 */
#define is_large_obj(p)	(inpage_offset(p) == sizeof(Large_Obj_Block))

/*	A memory pool	*/

typedef struct {
	size_t freeOffset;
	size_t count;
	char start[];
} Pool;

typedef struct {
	size_t size;
	char start[];
} Large_Obj_Block;

static Pool *pool = NULL;

static void *
alloc_single_page(void)
{
	return mmap(NULL, 4096, PROT_READ | PROT_WRITE,
		    MAP_ANONYMOUS | MAP_PRIVATE,
		    -1, 0);
}

static inline int
create_pool(void)
{
	Pool *p = alloc_single_page();
	if (pool == MMAP_FAILED)
		return -1;
	p->freeOffset	= 0;
	p->count	= 0;
	pool = p;
	return 0;
}


static inline void *
alloc_small_obj(size_t size)
{
	if (!pool || free_size < size) {
		if (create_pool())
			return NULL;
	}

	void *res = (void*)(pool->start + pool->freeOffset);

	pool->freeOffset += size;
	pool->count++;

	return res;
}

void *
malloc(size_t size)
{
	const size_t haltPageSize = 2048;
	if (size > haltPageSize)
		abort();
	else
		return alloc_small_obj(size);
}

static inline void
try_free_pool(Pool *thisPool)
{
	if (thisPool != pool && !thisPool->count &&
	    thisPool->freeOffset < HALF_PAGE_SIZE)
	    	assert(!munmap(thisPool, PAGE_SIZE));
	return;
}

static inline void
free_small_obj(void *p)
{
	Pool *thisPool = page_start(p);
	thisPool->count--;
	try_free_pool(thisPool);
	return;
}

void
free(void *p)
{
	if (!p)
		return;

	if (is_large_obj(p))
		abort();
	else
		free_small_obj(p);
	return;
}
