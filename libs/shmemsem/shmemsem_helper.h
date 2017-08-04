/*
 * Copyright (c) 2017 Fraunhofer FOKUS
 *
 * Licensed under the MIT License (the "License");
 * you may not use this file except in compliance with the License.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * based on Keith Gaughan - Shared Memory and Semaphores - March 22, 2003
 */
#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <assert.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#if !defined(__GNU_LIBRARY__) || defined(_SEM_SEMUN_UNDEFINED)
union semun
{
	int val;				// value for SETVAL
	struct semid_ds* buf;	// buffer for IPC_STAT, IPC_SET
	unsigned short* array;	// array for GETALL, SETALL
	struct seminfo* __buf;	// buffer for IPC_INFO
};
#endif

#ifndef SHMEM_SEM_HELPER
#define SHMEM_SEM_HELPER

/*
 * FAMIUM SPECIFIC
 */

// static info exchange shmem
struct shmem_info {
    int32_t idSidShMem;
    int32_t idIvShMem;
    int32_t idSampleShMem;
    int32_t idSubsampleDataShMem;
    uint32_t sidSize;
    uint32_t ivSize;
    uint32_t sampleSize;
    uint32_t subsampleDataSize;
};

enum {
  SEM_XCHNG_PUSH,
  SEM_XCHNG_DECRYPT,
  SEM_XCHNG_PULL
};

/*
 * GENERAL SHARED MEM AND SEMAPHORES
 */

// Declarations for wrapper functions...
int AllocateSharedMemory(int n);
void* MapSharedMemory(int id);
void* MapExistingSharedMemory(int id, void* existingAddr);
int DetachExistingSharedMemory(void* existingAddr);
int CreateSemaphoreSet(int n, unsigned short* vals);
void DeleteSemaphoreSet(int id);
void LockSemaphore(int id, int i);
void UnlockSemaphore(int id, int i);

#endif  /* SHMEM_SEM_HELPER */
