---
layout: default
title: Threads
nav_order: 8
parent: Linux Programming
---

# Introduction to threading: parallelism and concurrency
{: .no_toc }

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

Topic gives brief overview of the concept of **thread** in Linux operating system. It covers main aspects of parallel and concurrent execution, heap and stack memory layout and covers main differences between thread and process in terms of isolation, memory management and scheduling. The POSIX threads are introduced to cover thread programmability using **pthread** library. 

## Topic Outline

1. Overview of memory layout: heap and stack. The concept of call stack.
2. The concept of thread, thread context, main differences between process and thread.  
3. Understanding difference between parallel and concurrent execution.
4. Introduction to pthread library: creating, joining and cancelling threads. 

## Practice

1. Writing multi-threaded program using pthread library.
2. Using library functions to join and cancel threads.
3. Compilation and linking process with the pthread library.

