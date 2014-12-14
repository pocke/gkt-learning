package main

import (
	"os"

	"github.com/mattn/go-gtk/gtk"
)

func main() {
	gtk.Init(&os.Args)
	window := gtk.NewWindow(gtk.WINDOW_TOPLEVEL)

	window.SetSizeRequest(300, 200)

	button := gtk.NewButtonWithLabel("Quit")
	window.Add(button)
	button.Connect("clicked", func() {
		gtk.MainQuit()
	})

	window.ShowAll()
	gtk.Main()
}
