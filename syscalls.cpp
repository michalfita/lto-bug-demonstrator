/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2015, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) 2016, Schnaider Electric UK Ltd                                */
/*                                                                              */
/* All rights reserverd. Modifications are solely proprietary code of Schneider */
/* Electric and distribution in a form of a source code is not allowed without  */
/* specific prior written permission.                                           */
/* ---------------------------------------------------------------------------- */

/**
 * \file syscalls.c
 *
 * Implementation of newlib syscall.
 *
 */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

extern "C"
{
/*----------------------------------------------------------------------------
 *        Exported variables
 *----------------------------------------------------------------------------*/

#undef errno
int errno;

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
void _exit(int status);
void _kill(int pid, int sig);
int _getpid (void);

caddr_t _sbrk (int incr)
{
	asm("bkpt #0x6"); // We should never use this in multitasking!
	return (caddr_t)-1;
}

void* _sbrk_r(struct _reent* r, ptrdiff_t increment)
{
    static char my_heap[4086] = {};
	static unsigned char* heap_free_start = reinterpret_cast<unsigned char*>(&my_heap[0]);
	static unsigned char* heap_free_end = reinterpret_cast<unsigned char*>(&my_heap[1]);

	unsigned char* prev_heap = heap_free_start;

	heap_free_start += increment;

	if (heap_free_start > heap_free_end)
	{
		r->_errno = ENOMEM;
		return (void*)-1;
	}

	return prev_heap;
}

int link(char const *old, char const *newChar)
{
	return -1;
}

int _close(int file)
{
	return -1;
}

int _fstat(int file, struct stat *st)
{
	st->st_mode = S_IFCHR;

	return 0;
}

int _isatty(int file)
{
	return 1;
}

int _lseek(int file, int ptr, int dir)
{
	return 0;
}

int _read(int file, char *ptr, int len)
{
	return 0;
}

int _write(int file, char *ptr, int len)
{
	int iIndex;
	for (iIndex = 0; iIndex < len; iIndex++, ptr++)
	{
	}

	return iIndex;
}

int _open (const char *name, int flags, int mode)
{
  //errno = ENOSYS;
  return -1;                    /* Always fails */

} /* _open () */

void _exit(int status)
{
#ifdef __thumb
      asm("BKPT 255");
#else
      for (;;);
#endif
}

void _kill(int pid, int sig)
{
	return;
}

int _getpid (void)
{
	return -1;
}

void abort(void)
{
   _exit(1);
}

}

extern "C"
{
   void __cxa_pure_virtual()
   {
#ifdef __thumb
      asm("BKPT 255");
#else
      for (;;);
#endif
   }
}

