---
layout: default
title: 'ENV-1: Environment Setup'
parent: Environment
grand_parent: Tasks
nav_order: 1
---

# ENV-1: Setup GNU/Linux Environment

### Requirements 

- Install any GNU/Linux distribution on a Virtual or Physical Machine.
- Run **lsb_release -a \>\> $USER.txt** command (if available) in a shell and get the result.
- Run **cat /etc/os-release \>\> $USER.txt** command (if available) in a shell and get the result.
- Submit $USER.txt file to the Github as a solution for the task.

### Expected output

The expected output is a text file named $USER.txt where $USER is the current user's username. The content is expected to be similar to the following:

```
Distributor ID: Distribution Name
Description:    Ubuntu 20.04.3 LTS
..... omitted 
NAME="Ubuntu"
VERSION="20.04.3 LTS (Focal Fossa)"
ID=ubuntu
..... omitted
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
VERSION_CODENAME=focal
UBUNTU_CODENAME=focal
```
