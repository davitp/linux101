---
layout: default
title: Advanced Input and Output
nav_order: 6
parent: Linux Programming
---

# The advanced input/output programming with File Systems API
{: .no_toc }

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

The topic covers more API functions and concept allowing further file manipulations for more advanced scenarios. API functions such as dup, dup2 and their usages are explained, more granular control while opening files (truncate-on-open, temporary, etc.). Also, the seek operation is described with its basic and advanced usages such as simple cursor moves and operations using holes and sparse files. 

## Topic Outline

1. Controlling standard input, output and error streams using file descriptor duplication (dup, dup2).
2. Granular control over open file descriptors: truncate-on-open, create if does not exist, temporary file, etc.
3. Seek (lseek) operation on open file, various modes of seeking the file, holes and sparse files.

## Practice

1. Advanced file operations using shell such as stream redirection, input/output pipe, grep, dd, etc.
2. Demonstrate ability to perform read and write operations on a random file locations using lseek.
3. Creating sparse files using lseek, detecting holes, etc.

