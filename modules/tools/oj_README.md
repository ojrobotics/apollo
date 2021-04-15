# Apollo Tools

For using `apollo/modules/tools/` in Apollo do the following:

* Inside docker, install: 

```bash
sudo apt-get install python3-tk
```

* Make a new folder inside `apollo` root dir and link it to `bazel-bin`. This will make a linkage for python correct import.

`cd apollo
ln -s /apollo/bazel-bin bazelbin` 

* In the  file `/apollo/scripts/apollo_base.sh`, add the following:
` pathprepend ${APOLLO_ROOT_DIR}/modules PYTHONPATH
  pathprepend ${APOLLO_ROOT_DIR}/bazelbin PYTHONPATH`

* Inside each python file you need to run add
