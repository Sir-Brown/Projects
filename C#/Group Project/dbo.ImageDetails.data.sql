/*DECLARE @imageTag VARCHAR(50) = imageTag; /*I need this to link to the imageTag variable from MainForm.cs.cs*/
DECLARE @imageName VARCHAR(50) = imageName; /*I need this to link to the fileName variable from MainForm.cs*/
DECLARE @imageDate DATE = dateUploaded; /I need this to link to the date variable from MainForm.cs*/

INSERT INTO [dbo].[ImageDetails] ([Image Tag], [Image Name], [Date Uploaded]) VALUES (1, N'Forest.jpg', N'2025-04-24')
/*INSERT INTO [dbo].[ImageDetails] ([Image Tag], [Image Name], [Date Uploaded]) VALUES (@imageTag, @imageName, @imageDate)*/