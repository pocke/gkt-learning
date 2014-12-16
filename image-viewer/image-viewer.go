package main

import (
	"fmt"
	"os"

	"github.com/mattn/go-gtk/gtk"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Printf("Usage: %s image-file\n", os.Args[0])
		os.Exit(1)
	}

	gtk.Init(&os.Args)

	// window
	window := gtk.NewWindow(gtk.WINDOW_TOPLEVEL)
	window.SetSizeRequest(300, 200)

	// vbox
	vbox := gtk.NewVBox(false, 2)
	window.Add(vbox)

	// scroll window
	scroll_window := gtk.NewScrolledWindow(nil, nil)
	scroll_window.SetPolicy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
	vbox.PackStart(scroll_window, true, true, 0)

	// image
	image := gtk.NewImageFromFile(os.Args[1])
	scroll_window.AddWithViewPort(image)

	// button
	button := gtk.NewButtonWithLabel("Quit")
	button.Connect("clicked", func() {
		gtk.MainQuit()
	})
	vbox.PackStart(button, false, false, 0)

	window.ShowAll()
	gtk.Main()
}
