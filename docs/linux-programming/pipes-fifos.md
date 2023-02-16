---
layout: default
title: Pipes and FIFO Files
nav_order: 13
parent: Linux Programming
---

# Anonymous pipes and FIFO files 
{: .no_toc }

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

The topic covers basic understanding of **pipe** files and the main differences of pipes from the regular files. It discusses the interface for creating anonymous pipes with pipe system call as well as using **FIFO** files (named pipes). 

## Topic Outline

1. What is pipe file, differences between pipe and regular files, pipe() system call.
2. Using anonymous pipes for parent/child inter-process communication.
3. Overview of named pipes (FIFOs) and using mkfifo() function. 
4. Differences between pipes and shared memory in terms of IPC (streaming and random access).

## Practice

1. Demonstrate communication between parent and child processes using anonymous pipes.
2. Using FIFOs to stream large data from one process to another.

