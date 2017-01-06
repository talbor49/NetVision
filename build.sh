#!/bin/bash
cd build
cmake ../ && make && cd .. && sudo build/NetVision enp3s0
