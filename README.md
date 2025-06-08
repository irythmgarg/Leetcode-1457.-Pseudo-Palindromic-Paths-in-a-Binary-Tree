# Leetcode-1457.-Pseudo-Palindromic-Paths-in-a-Binary-Tree

# 🔢 Pseudo-Palindromic Paths in a Binary Tree

Given a binary tree where each node contains a digit from 1 to 9, this project finds the number of **pseudo-palindromic** paths from root to leaf.

A **pseudo-palindromic path** is a path that can be rearranged to form a palindrome — i.e., at most one digit can have an odd frequency.

---

## 🧠 Approaches

We provide **two optimized approaches** for solving this problem:

---

### ✅ Approach 1: Frequency Array

This method uses an array of size 10 (for digits 1 to 9) to count the frequency of digits along each path.  
At each leaf node, it checks if at most one digit has an odd frequency.

#### ✔️ Key Points:
- Uses a `vector<int>` to maintain digit frequencies
- Performs a DFS traversal with backtracking
- Checks palindrome condition using a helper function

#### ⏱ Time Complexity: `O(N * 9)`  
(Traverses each node once, checks array of size 9)

#### 💾 Space Complexity: `O(H + 9)`  
(Recursion stack + frequency array)

---

### ⚡ Approach 2: Bit Manipulation

This is a space-optimized version using **bitmasking**.  
Instead of a frequency array, it uses a single `int` to represent odd/even frequency parity of digits using bits.

#### ✔️ Key Points:
- Uses XOR to toggle bits
- Checks palindrome condition by verifying if only one bit is set
- Faster and more memory-efficient

#### ⏱ Time Complexity: `O(N)`  
(Traverses each node once, bit ops are constant time)

#### 💾 Space Complexity: `O(H)`  
(Only recursion stack, no array)

---

## 📌 Summary Table

| Feature               | Frequency Array | Bit Manipulation |
|----------------------|------------------|------------------|
| Time Complexity       | O(N * 9)         | O(N)             |
| Space Complexity      | O(H + 9)         | O(H)             |
| Palindrome Check      | Count odds       | Bit parity       |
| Performance           | Good             | Excellent        |
| Readability           | Easier           | Requires bitwise knowledge |

---

## ✍️ Author

**Ridham Garg**  
👨‍💻 Passionate Computer Engineer | Problem Solver | C++ Enthusiast  
🎓 Thapar University, Patiala  
📧 Let’s build efficient code together!

---

✨ If you found this helpful, don't forget to ⭐ the repo and try both methods to see the performance difference!
