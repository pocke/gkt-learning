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

	// image
	image := gtk.NewImageFromFile(os.Args[1])
	vbox.PackStart(image, true, true, 0)

	// button
	button := gtk.NewButtonWithLabel("Quit")
	button.Connect("clicked", func() {
		gtk.MainQuit()
	})
	vbox.PackStart(button, false, false, 0)

	window.ShowAll()
	gtk.Main()
}
