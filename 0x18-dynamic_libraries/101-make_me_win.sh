#!/bin/bash
wget -P /tmp https://github.com/gkiplangat/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libmask.so
export LD_PRELOAD=/tmp/libmask.so
