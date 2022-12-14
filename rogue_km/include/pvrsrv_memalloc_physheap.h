/*************************************************************************/ /*!
@File           pvrsrv_memalloc_physheap.h
@Title          Services Phys Heap types
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@Description    Used in creating and allocating from Physical Heaps.
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ /**************************************************************************/
#ifndef PVRSRV_MEMALLOC_PHYSHEAP_H
#define PVRSRV_MEMALLOC_PHYSHEAP_H

#include "img_defs.h"

/*
 * These IDs are replicated in the Device Memory allocation flags to allow
 * allocations to be made in terms of their locality/use to ensure the correct
 * physical heap is accessed for the given system/platform configuration.
 * A system Phys Heap Config is linked to one or more Phys Heaps. When a heap
 * is not present in the system configuration the allocation will fallback to
 * the default GPU_LOCAL physical heap which all systems must define.
 * See PVRSRV_MEMALLOCFLAGS_*_MAPPABLE_MASK.
 *
 * NOTE: Enum order important, table in physheap.c must change if order changed.
 */
typedef enum
{
	/* Services client accessible heaps */
	PVRSRV_PHYS_HEAP_DEFAULT      = 0, /* default phys heap for device memory allocations */
	PVRSRV_PHYS_HEAP_GPU_LOCAL    = 1, /* used for buffers with more GPU access than CPU */
	PVRSRV_PHYS_HEAP_CPU_LOCAL    = 2, /* used for buffers with more CPU access than GPU */
	PVRSRV_PHYS_HEAP_GPU_PRIVATE  = 3, /* used for buffers that only required GPU read/write access, not visible to the CPU. */

	/* Services internal heaps */
	PVRSRV_PHYS_HEAP_FW_MAIN      = 4, /* runtime data, e.g. CCBs, sync objects */
	PVRSRV_PHYS_HEAP_EXTERNAL     = 5, /* used by some PMR import/export factories where the physical memory heap is not managed by the pvrsrv driver */
	PVRSRV_PHYS_HEAP_GPU_COHERENT = 6, /* used for a cache coherent region */
	PVRSRV_PHYS_HEAP_GPU_SECURE   = 7, /* used by security validation */
	PVRSRV_PHYS_HEAP_FW_CONFIG    = 8, /* subheap of FW_MAIN, configuration data for FW init */
	PVRSRV_PHYS_HEAP_FW_CODE      = 9, /* used by security validation or dedicated fw */
	PVRSRV_PHYS_HEAP_FW_PRIV_DATA = 10, /* internal FW data (like the stack, FW control data structures, etc.) */
	PVRSRV_PHYS_HEAP_FW_PREMAP0   = 11, /* Host OS premap fw heap */
	PVRSRV_PHYS_HEAP_FW_PREMAP1   = 12, /* Guest OS 1 premap fw heap */
	PVRSRV_PHYS_HEAP_FW_PREMAP2   = 13, /* Guest OS 2 premap fw heap */
	PVRSRV_PHYS_HEAP_FW_PREMAP3   = 14, /* Guest OS 3 premap fw heap */
	PVRSRV_PHYS_HEAP_FW_PREMAP4   = 15, /* Guest OS 4 premap fw heap */
	PVRSRV_PHYS_HEAP_FW_PREMAP5   = 16, /* Guest OS 5 premap fw heap */
	PVRSRV_PHYS_HEAP_FW_PREMAP6   = 17, /* Guest OS 6 premap fw heap */
	PVRSRV_PHYS_HEAP_FW_PREMAP7   = 18, /* Guest OS 7 premap fw heap */
	PVRSRV_PHYS_HEAP_LAST
} PVRSRV_PHYS_HEAP;


static_assert(PVRSRV_PHYS_HEAP_LAST <= (0x1FU + 1U), "Ensure enum fits in memalloc flags bitfield.");

typedef struct _PHYS_HEAP_MEM_STATS_
{
	IMG_UINT64	ePhysHeapID;
	IMG_UINT64	ui64TotalSize;
	IMG_UINT64	ui64FreeSize;
}PHYS_HEAP_MEM_STATS, *PHYS_HEAP_MEM_STATS_PTR;

#endif /* PVRSRV_MEMALLOC_PHYSHEAP_H */
