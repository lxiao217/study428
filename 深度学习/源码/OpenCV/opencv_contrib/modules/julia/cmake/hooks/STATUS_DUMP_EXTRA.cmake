# ========================= julia =========================
if(WITH_JULIA OR HAVE_JULIA)
  status("")
  status("  JULIA:" HAVE_JULIA THEN "YES" ELSE "NO")
  if(HAVE_JULIA)
    status("    Julia_EXECUTABLE:"         ${Julia_EXECUTABLE})
    status("    JlCxx_DIR:"         ${JlCxx_DIR})
    if(HAVE_JULIA MATCHES "YES")
        status("    JULIA_PKG_INSTALL_PATH:"         ${JULIA_PKG_INSTALL_PATH_HOOK})
    endif()
  endif()
endif()
