/* Sha3.h */
#ifndef SHA3_H
#define SHA3_H



#ifdef __cplusplus
extern "C" {
#endif

#define le2me_64(x) (x)
#define me64_to_le_str(to, from, length) memcpy((to), (from), (length))
#define IS_ALIGNED_64(p) (0 == (7 & ((const char*)(p) - (const char*)0)))
#define ROTL64(qword, n) ((qword) << (n) ^ ((qword) >> (64 - (n))))
#define SHA3_hash_size  32
#define sha3_max_permutation_size 25
#define sha3_max_rate_in_qwords 24
#define I64(x) x##LL

/**
 * SHA3 Algorithm context.
 */
typedef struct sha3_ctx
{
	/* 1600 bits algorithm hashing state */
	uint64_t hash[sha3_max_permutation_size];
	/* 1536-bit buffer for leftovers */
	uint64_t message[sha3_max_rate_in_qwords];
	/* count of bytes in the message[] buffer */
	unsigned rest;
	/* size of a message block processed at once */
	unsigned block_size;
} sha3_ctx;

/* methods for calculating the hash function */

void Sha3Init(sha3_ctx *ctx);
void Sha3Update(sha3_ctx *ctx, const unsigned char* msg, size_t size);
void Sha3Final(sha3_ctx *ctx, unsigned char* result);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* __cplusplus */

#endif /* Sha3.h */
