## Grade

| **Score** | **Description** |
| --------- | ----- |
| <p align="center"><img width="200px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl4/NetPractice/img/Score_100.png"></p> | **Mandatory part** (Bonus part not available) |

# Net Practice

## Table of Contents

1. [Project Overview](#project-overview)
2. [General Guidelines](#general-guidelines)
3. [Networking Concepts](#networking-concepts)
   * [What is TCP/IP?](#what-is-tcpip)
   * [Subnet Masks and CIDR](#subnet-masks-and-cidr)
   * [Routing Basics](#routing-basics)
   * [Troubleshooting Tips](#troubleshooting-tips)
4. [Preview of an Exercise](#preview-of-an-exercise)


## Project Overview

The Net_Practice project is a practical exercise designed to introduce participants to the fundamentals of networking. It consists of a series of 10 levels, each presenting a non-functioning network diagram that participants must troubleshoot and configure correctly. The goal is to understand and apply TCP/IP addressing principles while solving various networking issues to ensure the network operates effectively.

Participants will access a training interface through a web browser, where they can practice their skills by either logging in or using a correction version of the exercises. Each level requires the completion of specific tasks, and once successfully finished, participants can export their configurations for submission to their Git repository. This project not only enhances technical knowledge but also encourages hands-on experience in network configuration and problem-solving.

[back to contents](#table-of-contents)


## General Guidelines

| **#** | **Instruction** |
| ----- | --------------- |
|  `1`  | This project requires configuring small-scale virtual networks. |
|  `2`  | Understanding TCP/IP addressing is crucial to successfully complete the exercises. |
|  `3`  | There are 10 levels, each representing a unique network configuration challenge. |
|  `4`  | All exercises are completed in a browser-based training interface. The networks simulated are not real but mimic real-world scenarios. |

[back to contents](#table-of-contents)


## Networking Concepts

### What is TCP/IP?
TCP/IP (Transmission Control Protocol/Internet Protocol) is a suite of communication protocols used to interconnect network devices on the internet. It includes:
* **IP (Internet Protocol):** Responsible for addressing and routing data packets to the correct destination.
* **TCP (Transmission Control Protocol):** Ensures reliable transmission of data by establishing connections and verifying delivery.

TCP/IP operates on a layered model:
* **Application Layer:** Manages applications and user interfaces (e.g., HTTP, FTP).
* **Transport Layer:** Handles data transfer (e.g., TCP, UDP).
* **Internet Layer:** Manages logical addressing and routing (e.g., IP).
* **Network Access Layer:** Deals with hardware and physical transmission (e.g., Ethernet).

### Subnet Masks and CIDR
* **Subnet Mask:** A 32-bit number used to divide an IP address into a network and host portion. Common masks include:
  * `/24` (255.255.255.0): Supports up to 256 IPs (254 usable for hosts).
  * `/16` (255.255.0.0): Supports up to 65,536 IPs.
  * `/8` (255.0.0.0): Supports up to 16,777,216 IPs.
* **CIDR (Classless Inter-Domain Routing):** A method for specifying IP ranges using the format `192.168.1.0/24`, where `/24` indicates the number of fixed bits in the subnet mask.

### Routing Basics
Routing is the process of forwarding data packets between networks. Key components include:
* **Routers:** Devices that direct traffic between different subnets or networks.
* **Routing Table:** Contains information about reachable networks and their associated interfaces.
* **Default Gateway:** The IP address of a router where packets are sent if their destination is unknown.

### Troubleshooting Tips
* **Ping:** Use to test connectivity between devices (`ping 192.168.1.1`).
* **Traceroute:** Identifies the path packets take to reach a destination (`traceroute 8.8.8.8`).
* **Check Logs:** Review logs in the training interface for hints on misconfigurations.
* **Subnet Calculation:** Ensure that all devices in the same subnet have compatible IP ranges and masks.

[back to contents](#table-of-contents)


## Preview of an Exercise

In this case, we can see how we must configure several networks and subnets, where different devices, within the ranges allowed by their subnet masks, must be able to connect to each other, to devices in another network, and to the internet, using a switch and two routers to enable these connections.

<p align="center">
<img src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl4/NetPractice/img/NetPractice.png">
</p>

[back to contents](#table-of-contents)