## PROBLEM I (sockets)

When Internet subscribers are connected via ADSL (Asymmetric Digital Subscriber Line) technology, the upload rate is much lower than the download rate. This means that if UserClient downloads a large document from UserServer, the transfer is limited by the upload speed of UserServer. To reduce the transfer time, it is possible for UserClient to start downloading different fragments of the same document from several users who have a copy of the document. This technique is used by many P2P download platforms.

We want to implement a simple program based on this technique. You have to program with sockets in Java two programs executed respectively on the client and on the server machines:

- UserClient downloads fragments of a document from multiple servers
- UserServer_i provides the document fragments

### Question 1

What essential property must UserClient fulfill for this technique to benefit from the existence of multiple servers to speed up the download?

Is this property necessary for UserServer_i processes?

__Answer__:

To benefit from the existence of multiple servers to speed up the download, the UserClient must be able to download fragments of the document from multiple servers simultaneously. This means that the UserClient must be able to establish multiple TCP connections to different servers and download different fragments of the document over each connection.

This property is not necessary for UserServer_i processes as they only need to be able to serve the document fragments requested by the UserClient over a single TCP connection.


### Question 2
Both UserClient and UserServer_i programs have the following variables defined:

```java
final static String hosts[] = {"host1", "host2", "host3"};
final static int ports[] = {8081,8082,8083};
final static int nb = 3;
static String document[] = new String[nb];
```

A server starts by taking as parameter its server number (0, 1 or 2, the index in the `hosts` and `ports`). `document` is initialized in UserSever_i as `{"hello", "hanoi", "vietnam"}`. For requests, use Java object serialization. A request can simply send an index number (0 to 2) over a TCP connection and receive the string corresponding to the index.

Give an implementation of the UserClient and UserServer_i programs following this scheme.

## Folder Structure

The workspace contains two folders by default, where:

- `src`: the folder to maintain sources
- `lib`: the folder to maintain dependencies

Meanwhile, the compiled output files will be generated in the `bin` folder by default.

> If you want to customize the folder structure, open `.vscode/settings.json` and update the related settings there.

## Dependency Management

The `JAVA PROJECTS` view allows you to manage your dependencies. More details can be found [here](https://github.com/microsoft/vscode-java-dependency#manage-dependencies).
