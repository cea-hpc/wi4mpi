#if defined(_INTEL) || defined(_OMPI) || defined(_MPC)
__asm__(".global CCMPI_Aint_add\n"
#else
__asm__(".global PMPI_Aint_add\n"
        ".weak MPI_Aint_add\n"
        ".set MPI_Aint_add,PMPI_Aint_add\n"
#endif

        ".extern in_w\n"
        ".extern A__MPI_Aint_add\n"
        ".extern R__MPI_Aint_add\n"
#if defined(_INTEL) || defined(_OMPI) || defined(_MPC)
        ".type CCMPI_Aint_add,@function\n"
#else
        ".type PMPI_Aint_add,@function\n"
#endif
        ".text\n"
#if defined(_INTEL) || defined(_OMPI) || defined(_MPC)
        "CCMPI_Aint_add:\n"
#else
        "PMPI_Aint_add:\n"
#endif
#ifdef __aarch64__
        "adrp x8, :gottprel:in_w\n"
        "ldr x8, [x8, :gottprel_lo12:in_w]\n"
        "mrs x9, TPIDR_EL0\n"
        "ldr w8, [x9, x8]\n"
        "cbnz w8, inwrap_MPI_Aint_add\n"
        "b A__MPI_Aint_add\n"
        "inwrap_MPI_Aint_add:\n"
        "b R__MPI_Aint_add\n"
#else
        "push %rbp\n"
        "mov %rsp, %rbp\n"
        "sub $0x10, %rsp\n"
        "mov %rdi, -0x8(%rbp)\n"
        "mov %rsi, -0x10(%rbp)\n"
        ".byte 0x66\n"
        "leaq in_w@tlsgd(%rip), %rdi\n"
        ".value 0x6666\n"
        "rex64\n"
        "call __tls_get_addr@PLT\n"
        "mov -0x8(%rbp), %rdi\n"
        "mov -0x10(%rbp), %rsi\n"
        "leave\n"
        "cmpl $0x0, 0x0(%rax)\n"
        "jne inwrap_MPI_Aint_add\n"
        "jmp *A__MPI_Aint_add@GOTPCREL(%rip)\n"
        "inwrap_MPI_Aint_add:\n"
        "jmp *R__MPI_Aint_add@GOTPCREL(%rip)\n"
#endif
#if defined(_INTEL) || defined(_OMPI) || defined(_MPC)
        ".size CCMPI_Aint_add,.-CCMPI_Aint_add\n"
#else
        ".size PMPI_Aint_add,.-PMPI_Aint_add\n"
#endif

);
