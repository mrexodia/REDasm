import subprocess
import platform
import sys
import os
from datetime import datetime

OS_NAME           = str.capitalize(sys.platform)
ARCH              = platform.machine()
BUILD_DATE        = datetime.now().strftime("%Y%m%d")
BUILD_ID          = "REDasm_" + OS_NAME + "_" + ARCH  + "_" + BUILD_DATE
BUILD_ARCHIVE     = BUILD_ID + ".zip"
BUILD_REPO        = "REDasm-Builds"
DATABASE_REPO_URL = "https://github.com/REDasmOrg/REDasm-Database.git"

if os.getenv("GITHUB_TOKEN") == None:
    print("WARNING: Invalid GH-Token")
    BUILD_REPO_URL = "https://github.com/REDasmOrg/" + BUILD_REPO + ".git"
else:
    BUILD_REPO_URL = "https://" + os.getenv("GITHUB_TOKEN") + "@github.com/REDasmOrg/" + BUILD_REPO + ".git"