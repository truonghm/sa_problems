## PROBLEM II (RMI)

You have to realize a remote command execution service (like rsh) using Java RMI.

This service is composed of 2 programs:

- a Daemon.java program that must be launched on all the machines to which we want to be able to launch remote commands. This program registers an RMI object on its local RMIRegistry.

- A RE.java program that allows the execution of a remote command. This program interacts with the Daemon program of the site on which the command must be executed.

The RE program is used as follows: `java RE <host> <command>`.

The RE program receives in `args[0]` and `args[1]` the 2 strings host and command.

To execute a command locally on remote machines, we use: `localExec(String cmd);`

### Question 3

Give a Java implementation of the Daemon and RE programs.

### Question 4

We now want to manage the console display of the remotely executed command. We want the displays of the command to be done on the console of the client who launched the command.

Now we execute a command locally with: `localExec(String command, Console console);`

Console is a Java interface which provides the method
`println(String s);`

The executed command performs its displays by calling this method on the objeCtonsole passed in parameter `localExec()`.

Modify your previous implementation to allow the remote command to be displayed on the client computer.

## Folder Structure

The workspace contains two folders by default, where:

- `src`: the folder to maintain sources
- `lib`: the folder to maintain dependencies

Meanwhile, the compiled output files will be generated in the `bin` folder by default.

> If you want to customize the folder structure, open `.vscode/settings.json` and update the related settings there.

## Dependency Management

The `JAVA PROJECTS` view allows you to manage your dependencies. More details can be found [here](https://github.com/microsoft/vscode-java-dependency#manage-dependencies).
