---
layout: default
title: Signals
nav_order: 12
parent: Topics
---

# Using signals for the inter-process communication 
{: .no_toc }

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

The topic continues the discussion about different methods of inter-process communication. It covers the concept **signals** and **signal handling** for sending and handling asynchronous messages withing processes.

## Topic Outline

1. Introduction to the concept of signals and signal handling in UNIX operating systems.
2. Brief overview of standardized and commonly used signals in.
3. Sending signals from a process to another using **kill** system call and the **kill** shell command.
4. Handling incoming signals in a process using **sigactions**. 

## Practice

1. Write a program to send signals to other processes. 
2. Write a program that handles incoming signals, overrides the default behavior and executes custom code for the particular signals. 

