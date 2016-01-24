prepare:
	@gunzip --force -k 1.1/libgh*.gz
	@echo ""
	@echo "NOW DO: $ ln 1.1/libgh-armhf-x.a libgh.a"
	@echo "where"
	@echo "        <version>/libgh-<arch>-<platform>.a"
	@echo ""


