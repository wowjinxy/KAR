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
