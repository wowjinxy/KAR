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

### main/grkdtree

- Source: `src/kar/gr/grkdtree.c`
- Starting unit score: 97.64% fuzzy, 6 / 7 exact functions
- Ending unit score: 97.98% fuzzy, 6 / 7 exact functions
- Improved:
  - `kar_grkdtree_next_query_object_id_for_kind`: 95.30% -> 95.97%
- Discovery: declaring `object_index`, the tree pointer, the kind offset, and
  the kind record in target lifetime order aligns all four long-lived
  registers. Control flow and field offsets were already correct.
- Deferred: the remaining differences are ephemeral register allocation and
  scheduling in the linked-list traversal and visited-bit calculation. Three
  further source-shape experiments either regressed or did not change the
  score.
- GKYE01 object and report: passing; all six existing exact functions remain
  exact
- GKYJ01 source compile: passing (manual compile because this region has no
  `grkdtree` split yet)
- GKYP01 source compile: passing (manual compile because this region has no
  `grkdtree` split yet)
- Commit: `07193af`

### main/gryakuwhispywoods

- Source: `src/kar/gr/gryakuwhispywoods.c`
- Unit score: unchanged at 99.30% fuzzy, 7 / 8 exact functions
- Inspected:
  - `kar_gryakuwhispywoods_handle_kind69_grcoll_hit_damage`: 97.03%
- Deferred: target and current code differ only in the allocation of `pass`
  and the initial Yaku pointer to `r31` and `r30`. Four experiments covering
  an explicit pass local, declaration order, delayed Yaku assignment, and a
  `register` hint did not improve the score. All experiments were removed.
- No source commit

### main/grdata

- Source: `src/kar/gr/grdata.c`
- Unit score: unchanged at 96.24% fuzzy, 8 / 10 exact functions
- Inspected:
  - `kar_grdata__800ce7a0`: 92.54%
  - `kar_grdata__near_800ceb18`: 94.63%
- Discovery: the course resource table contains five interleaved pointers per
  stage kind. The loader's two archive calls and all field offsets agree with
  the binary. The gravity selector first tries null-position gravity, then
  spline gravity, and falls back to the model/default vector only when each
  preceding result is near zero.
- Deferred: bounded experiments for explicit resource-pointer copies, raw
  five-pointer indexing, direct model-motion pointer arithmetic, declaration
  order, nested gravity conditionals, explicit switch cases, and direct
  constant stores either compiled identically or regressed. All experiments
  were removed.
- No source commit

### main/wnparts

- Source: `src/kar/wn/wnparts.c`
- Unit score: unchanged at 99.74% fuzzy, 5 / 6 exact functions
- Inspected:
  - `kar_wnparts__near_80221ae0`: 95.00%
- Deferred: target and current instructions differ only in floating-point
  register allocation for timer, amount, and the clamp maximum. Declaration
  order, assignment order, field compound assignment, direct constant access,
  and explicit amount accumulation did not improve the score. All experiments
  were removed.
- No source commit

### main/grice1

- Source: `src/kar/gr/grice1.c`
- Unit score: unchanged at 99.88% fuzzy, 3 / 6 exact functions
- Inspected:
  - `kar_grice1_switch_trigger_pushoutwall_targets_by_stage_index`: 99.29%
  - `kar_grice1_switch_trigger_lighttunnel_pillar_entry_by_stage_index`:
    99.29%
  - `kar_grice1_switch_trigger_lasergate_ctrl_open_by_stage_index`: 99.29%
- Deferred: each wrapper differs only in the operand order of the commutative
  add that combines the ground pointer with `stage_index * 0x48`. Explicit
  entry pointers, a named offset, and integer-address arithmetic either
  compiled identically or regressed to an indexed load. All experiments were
  removed.
- No source commit

### main/gryakudownforcezone

- Source: `src/kar/gr/gryakudownforcezone.c`
- Starting unit score: 90.90% fuzzy, 3 / 6 exact functions
- Ending unit score: 96.84% fuzzy, 3 / 6 exact functions
- Improved:
  - `kar_gryakudownforcezone_query_force_vector`: 89.61% -> 96.08%
  - `kar_gryakudownforcezone_handle_collision_report_audio`: 81.78% -> 92.66%
  - `kar_gryakudownforcezone_play_contact_fgm_at_report`: 94.29% -> 99.68%
- Discoveries:
  - The zero constant at `0x805DF8A8` belongs to this translation unit; the
    prior literal emitted an anonymous duplicate relocation.
  - Ground map-object lookup is a typed array pointer followed by `+= index`.
    Keeping those as separate source operations recovers the target multiply,
    pointer add, and `yaku_gobj` field load.
  - The collision event pointer is loaded before zeroing the contact vector.
  - The FGM slot index is a function local, and the success path computes an
    explicit `slot * 0x14` byte offset.
- Deferred:
  - Force query: collision-root pointer scheduling only.
  - Collision audio: deadzone FPR allocation.
  - Contact FGM: one dead-register coalescing choice at 99.68%.
- GKYE01 object and report: passing; all three existing exact functions remain
  exact and data remains 100%
- GKYJ01 object: passing
- GKYP01 object: passing
- Commit: `7774205`

### main/gryakulasergate

- Source: `src/kar/gr/gryakulasergate.c`
- Unit score: unchanged at 97.55% fuzzy, 4 / 6 exact functions
- Inspected:
  - `kar_gryakulasergate_init_kind58_lasergate_ctrl`: 94.47%
  - `kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates`: 97.58%
- Discovery: the trigger function has the same 91 instructions as the target;
  all 37 differences are register allocation. The initializer's object search
  is also semantically correct; its substantive diff is an equivalent
  `beq` versus `bne` plus explicit branch selected by the optimizer.
- Deferred: a natural search loop regressed the initializer to 90.65%, while
  an explicit `bne` continuation compiled identically to the baseline. Both
  experiments were removed. The remaining differences are register coloring,
  one duplicated zero materialization, and equivalent branch shaping.
- No source commit

### main/grswitch

- Source: `src/kar/gr/grswitch.c`
- Starting unit score: 94.00% fuzzy, 1 / 4 exact functions
- Ending unit score: 96.69% fuzzy, 2 / 4 exact functions
- Newly exact:
  - `kar_grswitch__near_800e8888`: 96.68% -> 100.00%
- Improved:
  - `kar_grswitch__800e86dc`: 93.17% -> 97.48%
- Discoveries:
  - The switch activation path indexes the typed `GroundMapObject` array
    directly when loading `switch_param`; this recovers the target's indexed
    load with the field offset folded into the address.
  - The switch update path indexes `zone->entries[slot]` directly. The prior
    temporary entry pointer introduced an extra `addi` and changed every
    queue-field access.
- Deferred:
  - `kar_grswitch__800e85a8`: 92.95%; remaining differences are assertion and
    switch-array pointer register coloring. Reordering assignments compiled
    identically and was removed.
  - `kar_grswitch__800e86dc`: the remaining 31 operand differences are one
    cyclic allocation of the three long-lived pointers. Declaration reordering
    compiled identically and was removed.
- GKYE01 object and report: passing; both exact functions confirmed
- GKYJ01 object: passing
- GKYP01 object: passing

### main/grconveyer

- Source: `src/kar/gr/grconveyer.c`
- Starting unit score: 70.79% fuzzy, 1 / 3 exact functions
- Ending unit score: 84.20% fuzzy, 1 / 3 exact functions
- Improved:
  - `kar_grconveyer__800e8000`: 78.53% -> 92.78%
  - `kar_grconveyer__800e8338`: 52.32% -> 67.19%
- Discoveries:
  - The conveyor cross-product helper is alias-safe: it calculates into a
    temporary `Vec` and copies that result to the requested output. Direct
    stores allowed MWCC to fuse and reorder the vector math in both functions.
  - The spline conveyor sends a null spline-data case to a zero-return block at
    the end of the function rather than returning inline at the first check.
  - The spline path retains the face-array base, scaled face offset, and face
    normal as distinct locals before reloading the direction flags.
  - The radial conveyor measures the magnitude of `pos - origin`. The previous
    implementation incorrectly measured the untouched second vector returned
    by `kar_grcommon_get_conveyerpos_vectors_by_index`.
- Deferred:
  - Spline path: remaining differences include GPR/FPR allocation, assertion
    base materialization, face-bit extraction, and direction-vector stack-slot
    order. A direct repeated face-base expression regressed to 78.61% and was
    removed.
  - Radial path: control-block placement and local vector ordering remain
    different. Reusing the helper's second output directly regressed to 49.95%
    and was removed.
- GKYE01 object and report: passing; the existing exact function remains exact
  and data remains 100%
- GKYJ01 source compile: passing (manual compile because this region has no
  `grconveyer` split yet)
- GKYP01 source compile: passing (manual compile because this region has no
  `grconveyer` split yet)

### main/efanime

- Source: `src/kar/ef/efanime.c`
- Unit score: unchanged at 98.29% fuzzy, 8 / 10 exact functions
- Inspected:
  - `kar_efanime__near_80240084`: 94.31%
  - `kar_efanime__near_802401e8`: 92.18%
- Discovery: both functions have the same target instructions except for
  scheduling the high half of the `lbl_8055DA08` address before the JObj load.
  The end-frame query also has one redundant target compare consistent with an
  inlined `HSD_AObjGetEndFrame` assertion.
- Deferred: an explicit unwind pointer compiled identically; initializing the
  AObj output in its declaration regressed the first function to 86.11%; and a
  local inline end-frame accessor compiled identically. All experiments were
  removed. Recovering the remainder likely requires the original shared
  `aobj.h` inline/macro context rather than more local source shuffling.
- No source commit

### main/efcallback

- Source: `src/kar/ef/efcallback.c`
- Starting unit score: 98.70% fuzzy, 2 / 6 exact functions
- Ending unit score: 100.00% code and data, 6 / 6 exact functions
- Newly exact:
  - `kar_efcallback__80234e4c`: 97.39% -> 100.00%
  - `kar_efcallback__near_802350a0`: 98.72% -> 100.00%
  - `kar_efcallback__near_8023515c`: 98.46% -> 100.00%
  - `kar_efcallback__near_80235190`: 98.28% -> 100.00%
- Discoveries:
  - Effect-entry flags at `0x2C` are extracted as one-bit values after shifts,
    producing the target `extrwi` instructions rather than mask-only
    `rlwinm` tests.
  - Particle resource versions are promoted from `u16` storage to an `s32`
    local before comparison.
  - The effect bank-table base and `bank * 4` offset are formed in separate
    statements. This preserves the target base and offset registers in both
    the setter and getter.
- Marked `efcallback.c` as matching after proving the complete object exact for
  GKYE01, GKYJ01, and GKYP01.
- GKYE01 full build, link, and checksum: passing
- GKYJ01 full build, link, and checksum: passing
- GKYP01 full build, link, and checksum: passing
- GKYE01 progress after linking: 19.60% fuzzy, 9.04% matched, 1.52% linked
  overall; Game Code 7.51% fuzzy, 3.97% matched, 1.15% linked

### main/emparts

- Source: `src/kar/em/emparts.c`
- Starting unit score: 81.51% fuzzy, 3 / 8 exact functions
- Ending unit score: 81.78% fuzzy, 4 / 8 exact functions
- Newly exact:
  - `kar_emparts__near_8020335c`: 98.02% -> 100.00%
- Improved:
  - `kar_emparts__near_80202c80`: 93.14% -> 95.29%
- Discoveries:
  - The enemy transform matrix is populated by columns: cross-product axis,
    scale, and direction. Its translation column is a chained zero assignment,
    which produces the target reverse store order.
  - The part-table walker does not retain `EmPartsConfig*`; it reloads
    `*config_ptr` when checking `count[kind]`, preserving the scaled kind index
    used by the target.
- Deferred:
  - Part-table walker: the remaining instructions and control flow match; its
    difference is a full loop-register permutation plus one temporary move.
  - Parts initializer: changing the `-2`/`-1` aliases to `s32` or direct
    literals compiled identically. Its remaining gap is config/index register
    allocation and optimizer placement of repeated loop setup.
  - The two large hierarchy/show-hide routines remain candidates for a later
    focused pass; this checkpoint avoided mixing their broader reconstruction
    with the verified narrow fixes.
- GKYE01 object and report: passing; all four exact functions confirmed and
  data remains 100%
- GKYJ01 object: passing
- GKYP01 object: passing

### main/gryakubreakfan

- Source: `src/kar/gr/gryakubreakfan.c`
- Unit fuzzy score: unchanged at 96.91%, 1 / 2 exact functions
- Corrected:
  - `kar_gryakubreakfan_trigger_kind30_break_effects_from_event`: replaced
    anonymous `0.0f` and `1.0f` literals with the target `.sdata2` symbols for
    all three regions.
- Discovery: the path-motion constants are US `lbl_805DFA68/6C`, Japanese
  `lbl_805DA490/94`, and PAL `lbl_805D24D0/D4`. Fuzzy scoring ignores these
  relocation identities, but objdiff confirms both target relocations now
  match in every region.
- Deferred: the only remaining differences are `li i`, `mr slot,yaku`, and
  `mr offset,i` scheduling. A comma-list `for` initializer compiled identically
  to the existing loop and was removed.
- GKYE01 object and objdiff: passing; existing exact cleanup remains exact
- GKYJ01 object and constant relocations: passing
- GKYP01 object and constant relocations: passing

### main/gmracecommon

- Source: `src/kar/gm/gmracecommon.c`
- Unit fuzzy score: 81.70% -> 84.28%
- Exact functions: 5 / 9 -> 7 / 9
- Matched code: 640 / 3204 bytes -> 1368 / 3204 bytes
- Matched:
  - `kar_gmracecommon__near_80013314`: 92.72% -> 100%
  - `kar_gmracecommon__near_800134d4`: 98.50% -> 100%
- Improved:
  - `kar_gmracecommon__near_800135ec`: 83.20% -> 86.69%
- Discoveries:
  - The race-option copies are direct byte-bitfield assignments. Using the
    established `gmmain` union layout reproduces both the source-to-destination
    `rlwimi` operations and the constant field writes.
  - The two `kar_gmracenormal__8003d5f0` return cases are one `||` condition;
    separate early returns omit a target branch.
  - The audio clock calculation multiplies the scale constant on the left.
    Reversing the commutative operands fixes the target FPR allocation.
  - The runtime conversion calls are `__cvt_dbl_usll` and `__cvt_sll_flt`;
    replacing raw address labels fixes their relocations.
  - The large player setup routine retains separate signed values for slot
    addressing and API calls. Its start-position and route values are `s8`,
    and start-position fields are loaded unsigned before the merged sign
    extension.
- Rejected:
  - Nesting the audio conversion calls compiled identically and was removed.
  - Changing the large routine parameter itself to `s8` regressed the function
    to 82.98% and was removed.
- Deferred:
  - `kar_gmracecommon__near_800135ec` still differs in pointer retention,
    repeated slot-field address formation, structure-copy shape, and remaining
    register allocation.
  - `kar_gmracecommon__near_800130a8` remains at 37.55% and needs a separate
    reconstruction pass.
- GKYE01 object and report: passing; both newly exact functions confirmed
- GKYJ01 source compile: passing
- GKYP01 source compile: passing

### main/grpointstrike

- Source: `src/kar/gr/grpointstrike.c`
- Unit restored unchanged at 97.49% after a bounded data-layout pass
- Discovery: the target assertion pool order is filename, panel-limit
  expression, joint-count expression, then stadium-kind expression. Natural
  first-use pooling places the stadium-kind expression first.
- Rejected:
  - A source-owned `const char` blob moved the strings to `.rodata` and grew
    the function.
  - A writable blob reproduced `.data` at 100%, but retaining its explicit
    pointer added a move and regressed text from 97.49% to 95.25%.
  - The `register` hint compiled identically to the regressed pointer form.
- Deferred: retain natural string pooling until a source form can reproduce
  the target pool without disturbing the function's register allocation.
- GKYE01 baseline object and report restored and passing

### main/grgravity

- Source: `src/kar/gr/grgravity.c`
- Unit restored unchanged at 95.99% after a bounded regional-constant pass
- Discovery: the target shared constants are:
  - GKYE01: `lbl_805DC8BC`, `lbl_805DF728`, `lbl_805DF72C`
  - GKYJ01: `lbl_805D7304`, `lbl_805DA150`, `lbl_805DA154`
  - GKYP01: `lbl_805CF26C`, `lbl_805D2190`, `lbl_805D2194`
- Rejected:
  - Volatile shared-constant loads regressed text to 91.73%.
  - Plain scalar externs regressed text to 94.24%.
  - Declaring the `FLT_MAX` symbol as the proven array type fixed its full
    address load but still changed later scheduling; the isolated version
    scored 95.25%.
- Deferred: the current literals preserve better instruction scheduling even
  though objdiff identifies their anonymous relocations.
- GKYE01 baseline object and report restored and passing

### main/grspline

- Source: `src/kar/gr/grspline.c`
- Unit fuzzy score: 94.42% -> 95.13%
- `kar_grspline_scale_all_spline_sets`: 93.28% -> 94.14%
- Discovery: loading the first course list before initializing its index and
  offset realigns the register allocation for all four middle spline-set loops.
- Rejected: initializing `offset` before `i` regressed the function to 92.85%
  and was removed.
- Deferred: the first course loop, spline-pair loop, and final vehicle loop
  still use different index/list register permutations.
- GKYE01 object and report: passing; both wrapper functions remain exact
- GKYJ01 object and objdiff: passing at the same 94.14%
- GKYP01 object and objdiff: passing at the same 94.14%

### main/plclearchecker

- Source: `src/kar/pl/plclearchecker.c`
- Unit restored unchanged at 55.53%, 12 / 16 exact functions
- Inspected:
  - `kar_plclearchecker_begin_object_action`: 98.61%
  - `kar_plclearchecker_end_object_action`: 98.61%
- Discovery: both wrappers are instruction-identical except for the target
  using `r5` for the scaled template offset while the current source uses `r4`.
- Rejected: making the scaled offset an explicit local compiled identically and
  was removed.
- GKYE01 baseline object and report restored and passing

### main/gryakurecoveryzone

- Source: `src/kar/gr/gryakurecoveryzone.c`
- Unit fuzzy score: 33.39% -> 33.44%
- Exact functions: 8 / 21 -> 9 / 21
- Matched:
  - `kar_gryakurecoveryzone_update_kind41_wait_then_extend`: 98.82% -> 100%
- Discovery: declaring `Kind41Param*` before the reloaded `Yaku*` produces the
  target `r31` parameter block and `r30` yaku allocation throughout the
  transition.
- Rejected:
  - Applying the analogous declaration swap to
    `kar_gryakurecoveryzone_enter_enabled_state_sequence` compiled identically
    and was removed.
  - Replacing the kind-42 search `goto` with a structured `break` and null test
    regressed that function from 98.04% to 92.05% and was removed.
- Deferred:
  - The raw GKYJ01/GKYP01 objects are instruction-identical for the newly
    matched function, but its anonymous `0.0f/1.0f` pair is one `.sdata2` slot
    earlier than target symbols `lbl_805DA30C/310` and
    `lbl_805D234C/350`. The full recovery-zone constant block must be
    reconstructed before those relocations can be linked exactly.
  - The enter-state function remains at 98.71% with an `r30/r31` allocation
    swap and constants owned by the preceding translation unit.
- GKYE01 object and report: passing
- GKYJ01 source compile and instruction diff: passing
- GKYP01 source compile and instruction diff: passing
