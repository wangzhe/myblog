<html>
<head>
	<script lang="javascript" src="https://cdn.rawgit.com/gitbrent/PptxGenJS/v2.0.0/dist/pptxgen.bundle.js"></script>

	<script>
		function myFunction(){
			var pptx = new PptxGenJS();
			var slide = pptx.addNewSlide();
			slide.addText('Hello Xinman!', { x:1.5, y:1.5, fontSize:18, color:'363636' });
			var slide2 = pptx.addSlidesForTable('tabAutoPaging');
			pptx.save('Sample Presentation');
		}
	</script>
</head>	
<body>
	<table id="tabAutoPaging" border="1">
		<thead>
			<tr>
				<th data-pptx-min-width="0.6" style="width: 5%">Row</th>
				<th data-pptx-min-width="0.8" style="width:10%">Last Name</th>
				<th data-pptx-min-width="0.8" style="width:10%">First Name</th>
				<th data-pptx-width="3.5"     style="width:75%">Description</th>
			</tr>
		</thead>
		<tbody>
			<tr>
				<th>1</th>
				<th>Wang</th>
				<th>Jack</th>
				<th>Description</th>
			</tr>
			<tr>
				<th>2</th>
				<th>Wang</th>
				<th>Syntax</th>
				<th>Description</th>
			</tr>
		</tbody>
	</table>

	<button onclick="myFunction()" type="button">Export to PPTX</button>

</body>
</html>