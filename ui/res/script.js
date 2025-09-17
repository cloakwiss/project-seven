document.addEventListener("DOMContentLoaded", () => {
  const TargetPathBox = document.getElementById("target_path");
  document.getElementById("target_pick").addEventListener("click", async () => {
    // call the Go backend
    const path = await window.PickTarget();
    if (path) {
      TargetPathBox.value = path;
    }
  });

  const HookdllPathBox = document.getElementById("hookdll_path");
  document.getElementById("hookdll_pick").addEventListener("click", async () => {
    // call the Go backend
    const path = await window.PickHookdll();
    if (path) {
      HookdllPathBox.value = path;
    }
  });
  
  document.getElementById("spawnp7").addEventListener("click", async() => {
	await window.SpawnP7();
  });

  document.getElementById("stop").addEventListener("click", async() => {
	await window.Stop();
  });

  document.getElementById("resume").addEventListener("click", async() => {
	await window.Resume();
  });

  document.getElementById("abort").addEventListener("click", async() => {
	await window.Abort();
  });

  document.getElementById("stec").addEventListener("click", async() => {
	await window.STEC();
  });

  document.getElementById("stsc").addEventListener("click", async() => {
	await window.STSC();
  });

  document.getElementById("stenc").addEventListener("click", async() => {
	await window.STENC();
  });

  document.getElementById("stsnc").addEventListener("click", async() => {
	await window.STSNC();
  });
});
