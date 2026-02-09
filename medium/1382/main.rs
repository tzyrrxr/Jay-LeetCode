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
    pub fn balance_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {

        let mut InorderList = Vec::new();
        // create inorder list
        Self::CreateInorderList(root.clone(), &mut InorderList);
        let n = InorderList.len();
        // build balance tree
        Self::CreateBalanceTree(&InorderList, 0, (n as i32)-1)
        
    }
    fn CreateInorderList (root: Option<Rc<RefCell<TreeNode>>>, InorderList: &mut Vec<i32>) {
        if let Some(n) = root {
            let node = n.borrow();
            Self::CreateInorderList(node.left.clone(), InorderList);
            InorderList.push(node.val);
            Self::CreateInorderList(node.right.clone(), InorderList);
        }
    }

    fn CreateBalanceTree (InorderList: &Vec<i32>, s:i32, e:i32) -> Option<Rc<RefCell<TreeNode>>> {
        if s > e {
            return None;
        }
        let mid = (s+e) >> 1;

        let mut node = TreeNode::new(InorderList[mid as usize]); 
        node.left = Self::CreateBalanceTree(InorderList, s, mid-1);
        node.right = Self::CreateBalanceTree(InorderList, mid+1, e);

        Some(Rc::new(RefCell::new(node)))
    }
}
