# Apollo Tools

For using `apollo/modules/tools/` in Apollo do the following:

* Inside docker, install: 

```bash
sudo apt-get install python3-tk
```

* Make a new folder inside `apollo` root dir and link it to `bazel-bin`. This will make a linkage for python correct import.

```bash
cd apollo

ln -s /apollo/bazel-bin bazelbin
``` 

* In the file `/apollo/scripts/apollo_base.sh`, add the following to set the PYTHONPATH:

```bash
pathprepend ${APOLLO_ROOT_DIR}/modules PYTHONPATH
pathprepend ${APOLLO_ROOT_DIR}/bazelbin PYTHONPATH
```

* Inside each python file you need to run add:

```bash
import sys
sys.path.append('/apollo')
```

* For any file includes `_bp2` in the `from` to import, add `bazelbin.` to any `from`. For example, in `/apollo/modules/tools/mapshow/libs/localization.py`, 

```bash
from bazelbin.modules.localization.proto.localization_pb2
```

Note that to run `gmapviewr.py`, you need _Goole Maps Platform API's key_.   

