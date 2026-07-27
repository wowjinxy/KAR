# Long Auto Test Run

Branch: `long-auto-test`

## Baseline

- GKYE01 build: passing
- Overall: 19.60% fuzzy, 9.02% matched, 1.50% linked
- Game code: 7.50% fuzzy, 3.94% matched, 1.12% linked
- Checkboxes: 192 / 360

## Translation Unit Passes

### main/mpcoll

- Source: `src/kar/mp/mpcoll.c`
- Starting unit score: 98.13% fuzzy, 8 / 9 exact functions
- Ending unit score: 100.00% fuzzy, 9 / 9 exact functions
- Newly exact:
  - `kar_mpcoll_check_special_face_kind3_enabled`: 68.77% -> 100.00%
- Discovery: the original source indexes the `0x40`-byte face-entry array
  directly before loading its data pointer at offset `0x38`. The prior byte
  pointer arithmetic was semantically equivalent but produced a different
  instruction sequence.
- GKYE01 object: passing
- GKYJ01 object: passing
- GKYP01 object: passing
- Commit: `a71eea3`
