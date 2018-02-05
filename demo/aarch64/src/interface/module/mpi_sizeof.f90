MODULE MPI_SIZEOFS
IMPLICIT NONE

PUBLIC :: MPI_SIZEOF
INTERFACE MPI_SIZEOF
MODULE PROCEDURE MPI_SIZEOF_0
MODULE PROCEDURE MPI_SIZEOF_1
MODULE PROCEDURE MPI_SIZEOF_2
MODULE PROCEDURE MPI_SIZEOF_3
MODULE PROCEDURE MPI_SIZEOF_4
MODULE PROCEDURE MPI_SIZEOF_5
MODULE PROCEDURE MPI_SIZEOF_6
MODULE PROCEDURE MPI_SIZEOF_7
MODULE PROCEDURE MPI_SIZEOF_8
MODULE PROCEDURE MPI_SIZEOF_9
MODULE PROCEDURE MPI_SIZEOF_10
MODULE PROCEDURE MPI_SIZEOF_11
MODULE PROCEDURE MPI_SIZEOF_12
MODULE PROCEDURE MPI_SIZEOF_13
MODULE PROCEDURE MPI_SIZEOF_14
MODULE PROCEDURE MPI_SIZEOF_15
MODULE PROCEDURE MPI_SIZEOF_16
MODULE PROCEDURE MPI_SIZEOF_17
END INTERFACE !MPI_Sizeof
CONTAINS

SUBROUTINE MPI_SIZEOF_0( X, SIZE, RES )
INTEGER X
INTEGER SIZE, RES
RES=0
SIZE=4
END SUBROUTINE MPI_SIZEOF_0

SUBROUTINE MPI_SIZEOF_1( X, SIZE, RES )
REAL X
INTEGER SIZE, RES
RES=0
SIZE=4
END SUBROUTINE MPI_SIZEOF_1

SUBROUTINE MPI_SIZEOF_2( X, SIZE, RES )
DOUBLE PRECISION X
INTEGER SIZE, RES
RES=0
SIZE=8
END SUBROUTINE MPI_SIZEOF_2

SUBROUTINE MPI_SIZEOF_3( X, SIZE, RES )
LOGICAL X
INTEGER SIZE, RES
RES=0
SIZE=4
END SUBROUTINE MPI_SIZEOF_3

SUBROUTINE MPI_SIZEOF_4( X, SIZE, RES )
CHARACTER X
INTEGER SIZE, RES
RES=0
SIZE=1
END SUBROUTINE MPI_SIZEOF_4

SUBROUTINE MPI_SIZEOF_5( X, SIZE, RES )
COMPLEX X
INTEGER SIZE, RES
RES=0
SIZE=8
END SUBROUTINE MPI_SIZEOF_5

SUBROUTINE MPI_SIZEOF_6( X, SIZE, RES )
INTEGER X(*)
INTEGER SIZE, RES
RES=0
SIZE=4
END SUBROUTINE MPI_SIZEOF_6

SUBROUTINE MPI_SIZEOF_7( X, SIZE, RES )
REAL X(*)
INTEGER SIZE, RES
RES=0
SIZE=4
END SUBROUTINE MPI_SIZEOF_7

SUBROUTINE MPI_SIZEOF_8( X, SIZE, RES )
DOUBLE PRECISION X(*)
INTEGER SIZE, RES
RES=0
SIZE=8
END SUBROUTINE MPI_SIZEOF_8

SUBROUTINE MPI_SIZEOF_9( X, SIZE, RES )
LOGICAL X(*)
INTEGER SIZE, RES
RES=0
SIZE=4
END SUBROUTINE MPI_SIZEOF_9

SUBROUTINE MPI_SIZEOF_10( X, SIZE, RES )
CHARACTER X(*)
INTEGER SIZE, RES
RES=0
SIZE=1
END SUBROUTINE MPI_SIZEOF_10

SUBROUTINE MPI_SIZEOF_11( X, SIZE, RES )
COMPLEX X(*)
INTEGER SIZE, RES
RES=0
SIZE=8
END SUBROUTINE MPI_SIZEOF_11

SUBROUTINE MPI_SIZEOF_12( X, SIZE, RES )
INTEGER*8 X
INTEGER SIZE, RES
RES=0
SIZE=8
END SUBROUTINE MPI_SIZEOF_12

SUBROUTINE MPI_SIZEOF_13( X, SIZE, RES )
INTEGER*8 X(*)
INTEGER SIZE, RES
RES=0
SIZE=8
END SUBROUTINE MPI_SIZEOF_13

SUBROUTINE MPI_SIZEOF_14( X, SIZE, RES )
INTEGER*1 X
INTEGER SIZE, RES
RES=0
SIZE=1
END SUBROUTINE MPI_SIZEOF_14

SUBROUTINE MPI_SIZEOF_15( X, SIZE, RES )
INTEGER*1 X(*)
INTEGER SIZE, RES
RES=0
SIZE=1
END SUBROUTINE MPI_SIZEOF_15

SUBROUTINE MPI_SIZEOF_16( X, SIZE, RES )
INTEGER*2 X
INTEGER SIZE, RES
RES=0
SIZE=2
END SUBROUTINE MPI_SIZEOF_16

SUBROUTINE MPI_SIZEOF_17( X, SIZE, RES )
INTEGER*2 X(*)
INTEGER SIZE, RES
RES=0
SIZE=2
END SUBROUTINE MPI_SIZEOF_17





!      SUBROUTINE MPI_Sizeof_complex128_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_scalar
!
!      SUBROUTINE MPI_Sizeof_complex128_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r1
!
!      SUBROUTINE MPI_Sizeof_complex128_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r2
!
!      SUBROUTINE MPI_Sizeof_complex128_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r3
!
!      SUBROUTINE MPI_Sizeof_complex128_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r4
!
!      SUBROUTINE MPI_Sizeof_complex128_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r5
!
!      SUBROUTINE MPI_Sizeof_complex128_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r6
!
!      SUBROUTINE MPI_Sizeof_complex128_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r7
!
!      SUBROUTINE MPI_Sizeof_complex128_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r8
!
!      SUBROUTINE MPI_Sizeof_complex128_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r9
!
!      SUBROUTINE MPI_Sizeof_complex128_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r10
!
!      SUBROUTINE MPI_Sizeof_complex128_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r11
!
!      SUBROUTINE MPI_Sizeof_complex128_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r12
!
!      SUBROUTINE MPI_Sizeof_complex128_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r13
!
!      SUBROUTINE MPI_Sizeof_complex128_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r14
!
!      SUBROUTINE MPI_Sizeof_complex128_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex128_r15
!
!      SUBROUTINE MPI_Sizeof_complex32_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_scalar
!
!      SUBROUTINE MPI_Sizeof_complex32_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r1
!
!      SUBROUTINE MPI_Sizeof_complex32_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r2
!
!      SUBROUTINE MPI_Sizeof_complex32_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r3
!
!      SUBROUTINE MPI_Sizeof_complex32_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r4
!
!      SUBROUTINE MPI_Sizeof_complex32_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r5
!
!      SUBROUTINE MPI_Sizeof_complex32_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r6
!
!      SUBROUTINE MPI_Sizeof_complex32_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r7
!
!      SUBROUTINE MPI_Sizeof_complex32_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r8
!
!      SUBROUTINE MPI_Sizeof_complex32_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r9
!
!      SUBROUTINE MPI_Sizeof_complex32_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r10
!
!      SUBROUTINE MPI_Sizeof_complex32_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r11
!
!      SUBROUTINE MPI_Sizeof_complex32_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r12
!
!      SUBROUTINE MPI_Sizeof_complex32_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r13
!
!      SUBROUTINE MPI_Sizeof_complex32_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r14
!
!      SUBROUTINE MPI_Sizeof_complex32_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      COMPLEX(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex32_r15
!
!      SUBROUTINE MPI_Sizeof_complex64_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_scalar
!
!      SUBROUTINE MPI_Sizeof_complex64_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r1
!
!      SUBROUTINE MPI_Sizeof_complex64_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r2
!
!      SUBROUTINE MPI_Sizeof_complex64_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r3
!
!      SUBROUTINE MPI_Sizeof_complex64_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r4
!
!      SUBROUTINE MPI_Sizeof_complex64_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r5
!
!      SUBROUTINE MPI_Sizeof_complex64_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r6
!
!      SUBROUTINE MPI_Sizeof_complex64_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r7
!
!      SUBROUTINE MPI_Sizeof_complex64_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r8
!
!      SUBROUTINE MPI_Sizeof_complex64_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r9
!
!      SUBROUTINE MPI_Sizeof_complex64_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r10
!
!      SUBROUTINE MPI_Sizeof_complex64_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r11
!
!      SUBROUTINE MPI_Sizeof_complex64_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r12
!
!      SUBROUTINE MPI_Sizeof_complex64_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r13
!
!      SUBROUTINE MPI_Sizeof_complex64_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r14
!
!      SUBROUTINE MPI_Sizeof_complex64_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      COMPLEX(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_complex64_r15
!
!      SUBROUTINE MPI_Sizeof_int16_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_scalar
!
!      SUBROUTINE MPI_Sizeof_int16_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r1
!
!      SUBROUTINE MPI_Sizeof_int16_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r2
!
!      SUBROUTINE MPI_Sizeof_int16_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r3
!
!      SUBROUTINE MPI_Sizeof_int16_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r4
!
!      SUBROUTINE MPI_Sizeof_int16_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r5
!
!      SUBROUTINE MPI_Sizeof_int16_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r6
!
!      SUBROUTINE MPI_Sizeof_int16_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r7
!
!      SUBROUTINE MPI_Sizeof_int16_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r8
!
!      SUBROUTINE MPI_Sizeof_int16_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r9
!
!      SUBROUTINE MPI_Sizeof_int16_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r10
!
!      SUBROUTINE MPI_Sizeof_int16_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r11
!
!      SUBROUTINE MPI_Sizeof_int16_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r12
!
!      SUBROUTINE MPI_Sizeof_int16_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r13
!
!      SUBROUTINE MPI_Sizeof_int16_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r14
!
!      SUBROUTINE MPI_Sizeof_int16_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT16
!      INTEGER(INT16), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int16_r15
!
!      SUBROUTINE MPI_Sizeof_int32_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_scalar
!
!      SUBROUTINE MPI_Sizeof_int32_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r1
!
!      SUBROUTINE MPI_Sizeof_int32_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r2
!
!      SUBROUTINE MPI_Sizeof_int32_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r3
!
!      SUBROUTINE MPI_Sizeof_int32_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r4
!
!      SUBROUTINE MPI_Sizeof_int32_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r5
!
!      SUBROUTINE MPI_Sizeof_int32_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r6
!
!      SUBROUTINE MPI_Sizeof_int32_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r7
!
!      SUBROUTINE MPI_Sizeof_int32_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r8
!
!      SUBROUTINE MPI_Sizeof_int32_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r9
!
!      SUBROUTINE MPI_Sizeof_int32_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r10
!
!      SUBROUTINE MPI_Sizeof_int32_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r11
!
!      SUBROUTINE MPI_Sizeof_int32_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r12
!
!      SUBROUTINE MPI_Sizeof_int32_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r13
!
!      SUBROUTINE MPI_Sizeof_int32_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r14
!
!      SUBROUTINE MPI_Sizeof_int32_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT32
!      INTEGER(INT32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int32_r15
!
!      SUBROUTINE MPI_Sizeof_int64_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_scalar
!
!      SUBROUTINE MPI_Sizeof_int64_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r1
!
!      SUBROUTINE MPI_Sizeof_int64_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r2
!
!      SUBROUTINE MPI_Sizeof_int64_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r3
!
!      SUBROUTINE MPI_Sizeof_int64_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r4
!
!      SUBROUTINE MPI_Sizeof_int64_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r5
!
!      SUBROUTINE MPI_Sizeof_int64_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r6
!
!      SUBROUTINE MPI_Sizeof_int64_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r7
!
!      SUBROUTINE MPI_Sizeof_int64_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r8
!
!      SUBROUTINE MPI_Sizeof_int64_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r9
!
!      SUBROUTINE MPI_Sizeof_int64_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r10
!
!      SUBROUTINE MPI_Sizeof_int64_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r11
!
!      SUBROUTINE MPI_Sizeof_int64_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r12
!
!      SUBROUTINE MPI_Sizeof_int64_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r13
!
!      SUBROUTINE MPI_Sizeof_int64_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r14
!
!      SUBROUTINE MPI_Sizeof_int64_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT64
!      INTEGER(INT64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int64_r15
!
!      SUBROUTINE MPI_Sizeof_int8_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_scalar
!
!      SUBROUTINE MPI_Sizeof_int8_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r1
!
!      SUBROUTINE MPI_Sizeof_int8_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r2
!
!      SUBROUTINE MPI_Sizeof_int8_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r3
!
!      SUBROUTINE MPI_Sizeof_int8_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r4
!
!      SUBROUTINE MPI_Sizeof_int8_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r5
!
!      SUBROUTINE MPI_Sizeof_int8_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r6
!
!      SUBROUTINE MPI_Sizeof_int8_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r7
!
!      SUBROUTINE MPI_Sizeof_int8_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r8
!
!      SUBROUTINE MPI_Sizeof_int8_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r9
!
!      SUBROUTINE MPI_Sizeof_int8_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r10
!
!      SUBROUTINE MPI_Sizeof_int8_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r11
!
!      SUBROUTINE MPI_Sizeof_int8_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r12
!
!      SUBROUTINE MPI_Sizeof_int8_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r13
!
!      SUBROUTINE MPI_Sizeof_int8_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r14
!
!      SUBROUTINE MPI_Sizeof_int8_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: INT8
!      INTEGER(INT8), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_int8_r15
!
!      SUBROUTINE MPI_Sizeof_real128_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_scalar
!
!      SUBROUTINE MPI_Sizeof_real128_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r1
!
!      SUBROUTINE MPI_Sizeof_real128_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r2
!
!      SUBROUTINE MPI_Sizeof_real128_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r3
!
!      SUBROUTINE MPI_Sizeof_real128_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r4
!
!      SUBROUTINE MPI_Sizeof_real128_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r5
!
!      SUBROUTINE MPI_Sizeof_real128_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r6
!
!      SUBROUTINE MPI_Sizeof_real128_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r7
!
!      SUBROUTINE MPI_Sizeof_real128_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r8
!
!      SUBROUTINE MPI_Sizeof_real128_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r9
!
!      SUBROUTINE MPI_Sizeof_real128_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r10
!
!      SUBROUTINE MPI_Sizeof_real128_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r11
!
!      SUBROUTINE MPI_Sizeof_real128_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r12
!
!      SUBROUTINE MPI_Sizeof_real128_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r13
!
!      SUBROUTINE MPI_Sizeof_real128_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r14
!
!      SUBROUTINE MPI_Sizeof_real128_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
!      REAL(REAL128), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real128_r15
!
!      SUBROUTINE MPI_Sizeof_real32_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_scalar
!
!      SUBROUTINE MPI_Sizeof_real32_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r1
!
!      SUBROUTINE MPI_Sizeof_real32_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r2
!
!      SUBROUTINE MPI_Sizeof_real32_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r3
!
!      SUBROUTINE MPI_Sizeof_real32_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r4
!
!      SUBROUTINE MPI_Sizeof_real32_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r5
!
!      SUBROUTINE MPI_Sizeof_real32_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r6
!
!      SUBROUTINE MPI_Sizeof_real32_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r7
!
!      SUBROUTINE MPI_Sizeof_real32_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r8
!
!      SUBROUTINE MPI_Sizeof_real32_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r9
!
!      SUBROUTINE MPI_Sizeof_real32_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r10
!
!      SUBROUTINE MPI_Sizeof_real32_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r11
!
!      SUBROUTINE MPI_Sizeof_real32_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r12
!
!      SUBROUTINE MPI_Sizeof_real32_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r13
!
!      SUBROUTINE MPI_Sizeof_real32_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r14
!
!      SUBROUTINE MPI_Sizeof_real32_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
!      REAL(REAL32), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real32_r15
!
!      SUBROUTINE MPI_Sizeof_real64_scalar(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_scalar
!
!      SUBROUTINE MPI_Sizeof_real64_r1(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r1
!
!      SUBROUTINE MPI_Sizeof_real64_r2(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r2
!
!      SUBROUTINE MPI_Sizeof_real64_r3(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r3
!
!      SUBROUTINE MPI_Sizeof_real64_r4(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r4
!
!      SUBROUTINE MPI_Sizeof_real64_r5(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r5
!
!      SUBROUTINE MPI_Sizeof_real64_r6(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r6
!
!      SUBROUTINE MPI_Sizeof_real64_r7(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r7
!
!      SUBROUTINE MPI_Sizeof_real64_r8(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r8
!
!      SUBROUTINE MPI_Sizeof_real64_r9(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r9
!
!      SUBROUTINE MPI_Sizeof_real64_r10(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r10
!
!      SUBROUTINE MPI_Sizeof_real64_r11(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r11
!
!      SUBROUTINE MPI_Sizeof_real64_r12(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r12
!
!      SUBROUTINE MPI_Sizeof_real64_r13(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r13
!
!      SUBROUTINE MPI_Sizeof_real64_r14(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r14
!
!      SUBROUTINE MPI_Sizeof_real64_r15(x, size, ierror)
!        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL64
!      REAL(REAL64), DIMENSION(1,1,1,1,1,1,1,1,1,1,1,1,1,1,*)::x
!        INTEGER, INTENT(OUT) :: size
!        INTEGER, INTENT(OUT) :: ierror
!      END SUBROUTINE MPI_Sizeof_real64_r15


END MODULE MPI_SIZEOFS
