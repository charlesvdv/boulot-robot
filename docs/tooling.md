# Tooling

## clang-tidy

### Fixing common issues automatically

At the root of the project, you can run:

```
clang-tidy -p ${BUILD_FOLDER}/compile_commands.json -header-filter=. -fix ${CPP_FILES}
```

where the variables are:

- `BUILDER_FOLDER`: the cmake build folder
- `CPP_FILES`: the cpp files you want to fix
