Padrick-x86_64.AppImage:
	pyoxidizer build --release --target-triple x86_64-unknown-linux-gnu
	cp -R build/x86_64-unknown-linux-gnu/release/install/* appdir/usr/bin
	appimagetool appdir

.PHONY: clean
clean:
	rm -rf build appdir/usr/bin/* Padrick-x86_64.AppImage
