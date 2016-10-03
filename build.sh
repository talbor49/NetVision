#!/bin/bash
cd build
cmake ../ && make && cd .. && sudo build/NetVision wlp2s0
