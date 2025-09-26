#include <hacks.h>
#include <sigexit.h>
#include <entry.h>
#include <lib.h>
#include <context.h>
#include <memory.h>

/*
 * Assumptions from gemOS:
 *  - hack_mode is one of: DIV_ZERO_OPER_CHANGE, DIV_ZERO_SKIP,
 *                         DIV_ZERO_USH_EXIT, DIV_ZERO_SKIP_FUNC
 *  - do_exit(int) terminates current process
 *  - struct user_regs has x86-64 fields: rax, rbx, rcx, rdx, rsi, rdi, rbp,
 *    rsp, rip, r8..r15 (as in include/context.h)
 *  - VMAs are in ctx->mms->vm_area, with access_flags containing PROT_EXEC
 */

struct hack_config {
    long cur_hack_config;
    u64  usr_handler_addr;
};



// Used to store current hack configuration (start as invalid)
static struct hack_config hconfig = { -1, (u64)-1 };


/* -------------------- syscall: configure -------------------- */

// system call handler to configure the hack semantics
long sys_config_hs(struct exec_context *ctx, long hack_mode, void *uhaddr)
{
  
}

/* -------------------- div-by-zero handler -------------------- */
int do_div_by_zero(struct user_regs *regs)
{
    // configuration must be valid
 

}
