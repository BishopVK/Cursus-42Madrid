## Grade

| **Score**           | **Description**     |
|-----------------------|---------------|
| <p align="center"><img width="222px" alt="170px" src="https://github.com/BishopVK/Cursus-42Madrid/blob/main/lvl1/Born2beRoot/img/Score_125.png"></p> | **Mandatory part + Full bonus part**   |


## Born2beRoot

I set up my first server using virtualization with VirtualBox. This project involved configuring the server with a minimal number of services, implementing strong password policies, and setting up SSH and firewall rules. Additionally, I created a monitoring script to display system information periodically. The objective was to learn the fundamentals of system administration and ensure the server operates securely and efficiently.


## Instruction set

To meet the objectives of the mandatory part of the project, the following rules must be followed:

| **#** | **Instruction**                                                                                                                                                           |
| ----- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Virtualization:** Use VirtualBox (or UTM if VirtualBox is not available) to create your virtual machine. |
|  `2`  | **Operating System:** Install the latest stable version of Debian or Rocky Linux (Debian is recommended for beginners). |
|  `3`  | **Minimal Services:** Configure the server with the minimal number of services. Do not install any graphical interface like X.org. |
|  `4`  | **SSH Configuration:** <ul><li>SSH must run on port 4242 only.</li><li>Root login via SSH should be disabled.</li><li>Use SSH to create a new user during the defense.</li></ul> |
|  `5`  | **Firewall Configuration:** <ul><li>Use UFW (or firewalld for Rocky) to configure the firewall, allowing only port 4242.</li><li>The firewall must be active when the virtual machine runs.</li></ul> |
|  `6`  | **Hostname:** Set the hostname of the virtual machine to your login followed by "42" (e.g., wil42). |
|  `7`  | **User and Groups:** <ul><li>Create a user with your login name.</li><li>This user must belong to the groups user42 and sudo.</li><li>Implement a strong password policy for all users.</li></ul> |
|  `8`  | **Password Policy:** <ul><li>Passwords must expire every 30 days.</li><li>Minimum days between password changes should be 2.</li><li>Users should receive a warning 7 days before password expiration.</li><li>Passwords must be at least 10 characters long, include an uppercase letter and a number, and not contain the username.</li><li>Root password must also follow this policy.</li></ul> |
|  `9`  | **Sudo Configuration:** <ul><li>Limit authentication attempts to three.</li><li>Display a custom message on incorrect password attempts.</li><li>Log all sudo commands to /var/log/sudo/.</li><li>Enable TTY mode for sudo.</li><li>Restrict accessible directories for sudo.</li></ul> |
|  `10`  | **Monitoring Script:** Create a monitoring.sh script that displays system information every 10 minutes. This includes: <ul><li>OS architecture and kernel version</li><li>Number of physical and virtual CPUs</li><li>Available RAM and usage percentage</li><li>Disk usage</li><li>CPU load</li><li>Last reboot date and time</li><li>LVM status</li><li>Number of active connections</li><li>Number of users</li><li>Server's IPv4 address and MAC address</li><li>Number of sudo commands executed</li></ul> |


## The Bonus part

<p>To fully complete the bonus part of the project, the following conditions must be met:</p>

| **#** | **Instruction**                                                                                                                                                                 |
| ----- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  `1`  | **Complete Mandatory Part:** Ensure that the mandatory part of the project is fully completed and meets all specified requirements. |
|  `2`  | **Additional Partition Configuration:** Configure the partitions to achieve a structure similar to the example provided in the project instructions. |
|  `3`  | **WordPress Site:** Set up a functional WordPress site using the following services: <ul><li>Lighttpd</li><li>MariaDB</li><li>PHP</li></ul> |
|  `4`  | **Additional Useful Service:** Configure an additional service of your choice (excluding NGINX/Apache2). You must justify your choice during the defense. <ul><li>**FTP (File Transfer Protocol):** a standard network protocol used for transferring files between computers over a network.</li><li>**FileZilla:** a popular open-source FTP client software that allows users to transfer files between their local computer and a remote server.</li><li>**Encapsulating users in an FTP directory:** restricting their access within a specific directory on the FTP server.</li></ul> |
|  `5`  | **Firewall Rules for Bonus Services:** Adapt the UFW or firewalld rules to accommodate any additional ports needed for the bonus services. |

<p>The bonus part will only be evaluated if the mandatory part is perfect. "Perfect" means that the mandatory part is fully functional and complete. If any part of the mandatory requirements is not fulfilled, the bonus will not be considered.</p>