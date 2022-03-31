/**
 * Copyright Notice:
 * Copyright 2022 DMTF. All rights reserved.
 * License: BSD 3-Clause License. For full text see link: https://github.com/DMTF/libspdm/blob/main/LICENSE.md
 **/

#include <base.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Suspends the execution of the current thread until the time-out interval elapses.
 *
 * @param milliseconds     The time interval for which execution is to be suspended, in milliseconds.
 *
 **/
void libspdm_sleep(uint64_t milliseconds)
{
    k_usleep((uint32_t)milliseconds);
}
