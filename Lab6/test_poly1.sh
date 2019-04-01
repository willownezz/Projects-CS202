#!/bin/sh

set -v

./poly_class_v1 << EOF
2
3 -2 1
2
2 2 2
EOF

./poly_class_v1 << EOF
2
1 2 3
3
1 2 3 4
EOF
