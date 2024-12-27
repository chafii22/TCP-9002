
# TCP Project

## Overview

This project implements a basic TCP server-client architecture using C. The server listens for incoming connections and allows clients to communicate by sending and receiving message

## why TCP and not UDP

TCP (Transmission Control Protocol) is chosen over UDP (User Datagram Protocol) for applications requiring reliable data transmission. Unlike UDP, which is connectionless and does not guarantee delivery, TCP establishes a connection and ensures that data packets are delivered in order and without loss. This reliability is crucial for applications like web browsing, file transfers, and email, where data integrity and completeness are essential. Additionally, TCP's built-in mechanisms for error checking and flow control make it ideal for scenarios where accurate communication is paramount, making it the preferred choice for most client-server applications
