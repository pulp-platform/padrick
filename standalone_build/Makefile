Padrick-x86_64.AppImage: appimagetool
	pyoxidizer build --release --target-triple x86_64-unknown-linux-gnu
	mkdir -p appdir/usr/bin
	cp -R build/x86_64-unknown-linux-gnu/release/install/* appdir/usr/bin
	./appimagetool appdir

appimagetool:
	wget https://github.com/AppImage/AppImageKit/releases/download/continuous/appimagetool-x86_64.AppImage -O ./appimagetool
	chmod a+x ./appimagetool

.PHONY: clean
clean:
	rm -rf build appdir/usr/bin/* Padrick-x86_64.AppImage
