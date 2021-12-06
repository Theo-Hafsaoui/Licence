/*Set of singleton represneted by a single singleton call
 * lead:
 *   +------o
 * lead(o)<-----o
 */
typedef struct _set_ {
    int n;
    struct _set_ * nxt;
    struct _set_ * lead;
} elm_set, * set;

set singleton(int i);
void Union(set x, set y);
set rep(set x);
