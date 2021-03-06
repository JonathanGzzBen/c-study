    processor 6502

    include "vcs.h"
    include "macro.h"
    
    seg code
    org $F000           ; defines the origin of the ROM at $F000

START:
    CLEAN_START         ; Macro to safely clear the memory
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Set background luminosity color to yellow
;; Colors can be consulted in https://en.wikipedia.org/wiki/List_of_video_game_console_palettes
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    lda #$1E            ; Load color into A ($1E is NTSC yellow)
    sta COLUBK          ; Store A to BackgroundColor Address $09
    
    jmp START           ; Repeat from START
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Fill ROM size to exactly 4KB
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    org $FFFC           ; Defines origin to $FFFC
    .word START         ; Reset vector at $FFFC (where program starts)
    .word START         ; Interrupt vector at $FFFE (unused)