#!/bin/sh

set -v

./poly_struct_v2 << EOF
2
3 -2 1
2
2 2 2
EOF

./poly_struct_v2 << EOF
2
1 2 3
3
1 2 3 4
EOF
