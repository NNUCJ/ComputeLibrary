'''
2023 by ICLEAGUE Author, All Rights Reserved.
Description: 
Author: Paul Cheng(成杰)
version: V0.1
Date: 2023-08-02 02:34:08
LastEditors: Paul Cheng(成杰)
FilePath: /ComputeLibrary/custom_test/npy_data/gen_npy.py
'''
import numpy as np

a = np.random.random((7, 5)).astype(np.float32)
b = np.random.random((5, 3)).astype(np.float32)
# dtype=
# a = np.dtype(np.float32)
# b = np.dtype(np.float32)
c = np.zeros((7,3), dtype=np.float32)
np.save("/workspace/mlc/ComputeLibrary/custom_test/npy_data/a.npy", a)
np.save("/workspace/mlc/ComputeLibrary/custom_test/npy_data/b.npy", b)
np.save("/workspace/mlc/ComputeLibrary/custom_test/npy_data/c.npy", c)