import Cascades 4.0

Container {
    layout: DockLayout {
            }
    ImageView {
        image: "assets://images/background"
        preferredWidth: 1024
        preferredHeight: 600
    }
    ListView {
        objectName: "postTypeList"
        preferredWidth: 300
        preferredHeight: 600
        layoutProperties: DockLayoutProperties {
                              horizontalAlignment: HorizontalAlignment.Left;
                          }
    }
    Container {
        layout: StackLayout {}
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Right;
            verticalAlignment: VerticalAlignment.Center
        }
        topMargin: 10
        bottomMargin: 10
        preferredWidth: 1024 - 300
        preferredHeight: 600
        Container {
            objectName: "postContainer"
            layout: StackLayout{}
            layoutProperties: StackLayoutProperties {
                                  horizontalAlignment: HorizontalAlignment.Center;
                                  verticalAlignment: VerticalAlignment.Center;
                              }
            preferredWidth: 1024 - 300
            topMargin: 10;
            leftMargin: 10;
            rightMargin: 10;
            TextField {
                preferredWidth: 1024-400;
                objectName: "postTitle";
            }
            TextArea {
                objectName: "postTextContent";
                preferredWidth: 1024-300;
                preferredHeight: 300;
            }
            
        }
        Button {
		    objectName: "postButton"
		    text: "Post"
        }
    }
}