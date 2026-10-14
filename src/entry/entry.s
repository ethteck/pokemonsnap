.include "macro.inc"

.section .text, "ax"

glabel entrypoint
    lui        $t0, %hi(main_BSS_START)
    lui        $t1, %lo(main_BSS_SIZE_HI)
    addiu      $t0, %lo(main_BSS_START)
    ori        $t1, %lo(main_BSS_SIZE_LO)

  .clear_bss:
    addi       $t1, -0x8
    sw         $zero, 0x0($t0)
    sw         $zero, 0x4($t0)
    addi       $t0, 0x8
    bnez       $t1, .clear_bss

  .enter_program:
    lui        $t2, %hi(game_main)
    lui        $sp, %hi(gThread0StackTop)
    addiu      $t2, %lo(game_main)
    addiu      $sp, %lo(gThread0StackTop)
    jr         $t2
endlabel entrypoint

.fill 0x60 - (. - entrypoint)
