(1) In VS Code carmaker-workspace öffnen

Mit Strg+Shif+P unter "Tasks: Run Task" folgende Tasks ausführen:
- (evtl) PSE: Clean Workspace
- PSE: Setup Environment
- PSE: Build
- PSE: Start CarMaker

Group-Number: 8

CarMaker wird durch die letzte Task ausgeführt. In CarMaker dann noch
- Car Modell hinzufügen
- IF launchen



(2) Ebenso in VS Code basic-workspace öffnen
Mit Strg+Shift+P den Befehl "Dev Container: Rebuild and Reopen in Container" Devcontainer starten

Folgende Tasks ausführen:
- (evtl) Clean Workspace
- Colcon: Build
- Launch: pse_aeb

Möchte man nur speziell die pse_aeb Node starten, so kann auch der Befehl "Run: pse_aeb" genutzt werden anstelle von "Launch: pse_aeb"

In einem weiteren Terminal dann folgende Befehle durchführen
- source /opt/ros/humble/setup.bash
- export ROS_DOMAIN_ID=38
- ros2 node list 
um node list anzeigen zu lassen
