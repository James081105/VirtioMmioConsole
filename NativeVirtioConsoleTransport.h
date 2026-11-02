// SPDX-License-Identifier: BSD-2-Clause-Patent
// Generic exclusive-owner kernel byte transport. No message/GPU semantics.
#pragma once
#include <IOKit/IOService.h>
extern "C" IOReturn native_console_send(IOService *,IOService *,const void *,size_t);
extern "C" IOReturn native_console_receive(IOService *,IOService *,void *,size_t *);
//: Report from kernel code that runs AFTER IOKit matching -- init's context,
//: for instance, which is where this board's SystemCryptex mount happens.  It
//: needs no open client, unlike native_console_send(), and returns
//: kIOReturnNotOpen when no console is live rather than dropping the bytes.
extern "C" IOReturn native_console_report(const void *,size_t);
//: Pull from kernel code that runs AFTER IOKit matching, as
//: native_console_report() is.  Unlike native_console_receive() this needs no
//: open client, and returns kIOReturnNotOpen when no console is live rather
//: than dropping the bytes.  A byte transport: no message or GPU semantics.
extern "C" IOReturn native_console_poll(void *,size_t *);
