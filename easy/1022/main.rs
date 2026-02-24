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
    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::DFS (&root, 0)
    }

    fn DFS (root: &Option<Rc<RefCell<TreeNode>>>, mut val: i32) -> i32 {
        if let Some(node) = root {
          let n = node.borrow();
          let curr_val = val*2 + n.val;

          if n.left.is_none() && n.right.is_none() {
              return curr_val;
          }

          return Self::DFS(&n.left, curr_val) + Self::DFS(&n.right, curr_val)
        } 

        0

    }

}
