All operations take O(lg n) amortized time.

For all 0 <= x, y < n,

* LinkCut tree(n); /* new link-cut tree with n nodes */
* tree.link(x, y); /* link x and y */
* tree.cut(x); /* cut x */
* tree.root(x); /* root of tree containing x */
* tree.depth(x); /* depth of x in its tree */
* tree.lca(x, y); /* lowest common ancestor of x and y */