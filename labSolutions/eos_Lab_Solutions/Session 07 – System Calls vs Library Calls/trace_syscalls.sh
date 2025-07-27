#!/bin/bash
echo "Tracing write_syscall:"
strace ./write_syscall
echo "Tracing printf_library:"
strace ./printf_library