// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn DFS(node: &Option<Rc<RefCell<TreeNode>>>) -> i32{
            match node {
                None => 0,
                Some(n) => {
                    let n = n.borrow();
                    let l = DFS(&n.left);
                    if l == -1 {
                        return -1;
                    }
                    let r = DFS(&n.right);
                    if r == -1 {
                        return -1;
                    }
                    if (l-r).abs() > 1 {
                        return -1;
                    }

                    1 + l.max(r)
                }
            }
        }

        DFS(&root) != -1
        
    }
}
