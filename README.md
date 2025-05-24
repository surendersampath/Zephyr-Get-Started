![Zephyr CI](https://github.com/YOUR_GITHUB_USERNAME/YOUR_REPOSITORY_NAME/actions/workflows/ci.yml/badge.svg)

# Zephyr-Get-Started

This repository serves as a template for learning and teaching Zephyr RTOS. It includes a sample application demonstrating Zephyr's synchronization features, along with a CI/CD setup using GitHub Actions for automated building and testing. By default, the sample application can be run on QEMU or as a native Linux application.

## Requirements

    1. Docker Desktop.
    
    Note.We are using Dev Containers so, Docker Desktop is all you need.

## Out of the box in the Dev Containers
Feature list of this project :

 - [x] 1. Set up a sample "Synchronization Demo" application to build for QEMU and native simulation using west.
 - [x] 2. Able to run the sample application on QEMU and native simulation using west.
 - [ ] 3. Add sample board support for ESP32/S3 or STM32. Nordic has plenty of online resources already.
 - [ ] 4. Github CodeSpace support.
 - [x] 5. CI/CD setup to automatically build and test the application.

## Running the Sample Application Locally

You can build and run the sample application using `west` from the root of this repository. The sample is located in the `app` directory and demonstrates a basic synchronization mechanism with two threads.

### Native Simulation (`native_sim`)

This runs the application as a native Linux process. It's generally faster for testing application logic that doesn't require specific hardware emulation.

```console
# Build for native_sim from the repository root
west build -p auto -b native_sim app

# Run the application (or its tests if defined)
# The build_dir defaults to 'build' if not specified, but we used 'app' as source_dir
# and native_sim as board, so west build -t run will look into build/native_sim
# or we can be explicit:
west build -t run --build-dir build/native_sim
```

### QEMU (`qemu_x86`)

This emulates an x86-based board using QEMU, providing a virtualized hardware environment.

```console
# Build for qemu_x86 from the repository root
west build -p auto -b qemu_x86 app

# Run the application in QEMU
west build -t run --build-dir build/qemu_x86
```
The console output will show messages from "thread_a" and "thread_b".

## CI/CD

This project uses GitHub Actions for Continuous Integration and Continuous Delivery (CI/CD). The workflow is defined in `.github/workflows/ci.yml`.

On every push to the `main` branch or any pull request targeting `main`, the following actions are performed automatically:
- The Zephyr environment is set up.
- The sample application in the `app` directory is built for the `native_sim` target.
- Automated tests (as defined in `app/sample.yaml`) are executed.

You can view the status of the CI runs in the "Actions" tab of this repository. The status badge at the top of this README also reflects the latest outcome.