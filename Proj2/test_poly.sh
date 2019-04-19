#!/bin/sh

set -v

./poly_class << EOF
2
1 2 3
2
4 5 6
EOF

./poly_class << EOF
4
3 3 3 3 3
2
9 8 7
EOF